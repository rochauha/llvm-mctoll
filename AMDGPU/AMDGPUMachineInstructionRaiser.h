//===-- AMDGPUMachineInstructionRaiser.h ------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of AMDGPUMachineInstructionRaiser class
// for use by llvm-mctoll.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TOOLS_LLVM_MCTOLL_AMDGPU_AMDGPUMACHINEINSTRUCTIONRAISER_H
#define LLVM_TOOLS_LLVM_MCTOLL_AMDGPU_AMDGPUMACHINEINSTRUCTIONRAISER_H

#include "MachineInstructionRaiser.h"

class AMDGPUMachineInstructionRaiser : public MachineInstructionRaiser {
public:
  AMDGPUMachineInstructionRaiser() = delete;
  AMDGPUMachineInstructionRaiser(MachineFunction &machFunc,
                                 const ModuleRaiser *mr, MCInstRaiser *mcir);
  bool raise() override;

  FunctionType *getRaisedFunctionPrototype() override;

  int getArgumentNumber(unsigned PReg) override;

  Value *getRegOrArgValue(unsigned PReg, int MBBNo) override;

  bool buildFuncArgTypeVector(const std::set<MCPhysReg> &,
                              std::vector<Type *> &) override;

  std::vector<JumpTableInfo> jtList;

private:
  bool raiseMachineFunction();
  // Commonly used LLVM data structures during this phase
  MachineRegisterInfo &machRegInfo;
};
#endif // LLVM_TOOLS_LLVM_MCTOLL_AMDGPU_AMDGPUMACHINEINSTRUCTIONRAISER_H
