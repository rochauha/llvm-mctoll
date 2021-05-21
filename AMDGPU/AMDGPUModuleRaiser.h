//===-- AMDGPUModuleRaiser.h ---------------------------------------*- C++
//-*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of AMDGPUModuleRaiser class for use by
// llvm-mctoll.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TOOLS_LLVM_MCTOLL_AMDGPU_AMDGPUMODULERAISER_H
#define LLVM_TOOLS_LLVM_MCTOLL_AMDGPU_AMDGPUMODULERAISER_H

#include "ModuleRaiser.h"

using namespace llvm;

class AMDGPUModuleRaiser : public ModuleRaiser {
public:
  AMDGPUModuleRaiser() : ModuleRaiser() {
    Arch = Triple::amdgcn;
    llvm::outs() << "Created AMDGPUModuleRaiser\n";
  }

  MachineFunctionRaiser *
  CreateAndAddMachineFunctionRaiser(Function *F, const ModuleRaiser *MR,
                                    uint64_t Start, uint64_t End) override;

  // We only have relocatable objects for AMDGPU.
  bool collectDynamicRelocations() override { return false; }
};

#endif // LLVM_TOOLS_LLVM_MCTOLL_AMDGPU_AMDGPUMODULERAISER_H
