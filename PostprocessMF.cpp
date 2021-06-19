#include "PostprocessMF.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/raw_ostream.h"

void postprocess(MachineFunctionRaiser *MFR) {
  postprocessBranches(MFR);
  // Todo postprocess call instruction sequence (s_swappc64 sqeuence)
}

void postprocessBranches(MachineFunctionRaiser *MFR) {
  MachineFunction &MF = MFR->getMachineFunction();
  for (auto &MBB : MF) {
    for (auto &MI : MBB) {
      // if (MI.getOpcode() == 14690) {
      // llvm::outs() << MI.getOpcode() << " " << MI.getNumOperands() << " ";
      // llvm::outs().flush();
      // MI.dump();
      // llvm::outs().flush();
      // }
      if (MI.isBranch())
        raiseBranchTargetAddress(MI, MF, MFR->getMCInstRaiser());
    }
  }
}

bool raiseBranchTargetAddress(MachineInstr &MI, MachineFunction &MF,
                              MCInstRaiser *mcInstRaiser) {
  assert(MI.isBranch() && "Instruction must be a branch instruction");

  int64_t branchTarget = -1;
  MachineOperand metadataOperand =
      MI.getOperand(1); // The extra metadata operand.

  if (!MI.isIndirectBranch()) {
    MachineOperand branchTargetOperand =
        MI.getOperand(0); // Only has one operand.

    if (branchTargetOperand.isImm())
      branchTarget = branchTargetOperand.getImm();
  }

  if (branchTarget == -1)
    return false;

  auto targetIndices = mcInstRaiser->getTargetIndices();
  if (targetIndices.find(branchTarget) == targetIndices.end())
    return false;

  int64_t MBBNum = mcInstRaiser->getMBBNumberOfMCInstOffset(branchTarget, MF);
  if (MBBNum == -1)
    return false;

  MI.RemoveOperand(1); // Remove metadata operand
  MI.RemoveOperand(0); // Remove branch operand

  MachineInstrBuilder MIB(MF, MI);
  MIB.addMBB(MF.getBlockNumbered(
      MBBNum)); // Add basic block corresponding to branch target address.
  MI.addOperand(metadataOperand); // Add metadata operand again.

  return true;
}
