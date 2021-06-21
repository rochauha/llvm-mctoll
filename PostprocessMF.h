#ifndef POSTPROCESS_MF_H
#define POSTPROCESS_MF_H

#include "MachineFunctionRaiser.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstr.h"

void postprocess(MachineFunctionRaiser *MFR);
void postprocessBranches(MachineFunctionRaiser *MFR);
bool raiseBranchTargetAddress(MachineInstr &MI, MachineFunction &MF,
                              MCInstRaiser *mcInstRaiser);

void removeMetadataOperands(MachineFunctionRaiser *MFR);

#endif
