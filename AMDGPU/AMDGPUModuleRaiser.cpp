//===-- AMDGPUModuleRaiser.cpp -------------------------------------*- C++
//-*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "AMDGPUModuleRaiser.h"
#include "MachineFunctionRaiser.h"
#include "llvm/Object/ELFObjectFile.h"

namespace RaiserContext {
extern SmallVector<ModuleRaiser *, 4> ModuleRaiserRegistry;
}

#ifdef __cplusplus
extern "C" {
#endif

void InitializeAMDGPUModuleRaiser() {
  ModuleRaiser *m = new AMDGPUModuleRaiser();
  RaiserContext::ModuleRaiserRegistry.push_back(m);
}

#ifdef __cplusplus
}
#endif
