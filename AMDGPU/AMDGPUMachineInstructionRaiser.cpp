//===-- AMDGPUMachineInstructionRaiser.cpp ----------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the implementation of AMDGPUMachineInstructionRaiser class
// for use by llvm-mctoll.
//
//===----------------------------------------------------------------------===//

#include "AMDGPUMachineInstructionRaiser.h"
#include "AMDGPUModuleRaiser.h"
#include "MachineFunctionRaiser.h"

using namespace llvm;

AMDGPUMachineInstructionRaiser::AMDGPUMachineInstructionRaiser(
    MachineFunction &machFunc, const ModuleRaiser *mr, MCInstRaiser *mcir)
    : MachineInstructionRaiser(machFunc, mr, mcir),
      machRegInfo(MF.getRegInfo()) {}

bool AMDGPUMachineInstructionRaiser::raiseMachineFunction() {
  // NYI
  assert(
      false &&
      "Unimplemented AMDGPUMachineInstructionRaiser::raiseMachineFunction()");
  return true;
}

bool AMDGPUMachineInstructionRaiser::raise() {
  raiseMachineFunction();
  return true;
}

int AMDGPUMachineInstructionRaiser::getArgumentNumber(unsigned PReg) {
  // NYI
  assert(false &&
         "Unimplemented AMDGPUMachineInstructionRaiser::getArgumentNumber()");
  return -1;
}

bool AMDGPUMachineInstructionRaiser::buildFuncArgTypeVector(
    const std::set<MCPhysReg> &PhysRegs, std::vector<Type *> &ArgTyVec) {
  // NYI
  assert(
      false &&
      "Unimplemented AMDGPUMachineInstructionRaiser::buildFuncArgTypeVector()");
  return false;
}

Value *AMDGPUMachineInstructionRaiser::getRegOrArgValue(unsigned PReg,
                                                        int MBBNo) {
  // NYI
  assert(false &&
         "Unimplemented AMDGPUMachineInstructionRaiser::getRegOrArgValue()");
  return nullptr;
}

FunctionType *AMDGPUMachineInstructionRaiser::getRaisedFunctionPrototype() {
  // NYI
  assert(false &&
         "Unimplemented "
         "AMDGPUMachineInstructionRaiser::getRaisedFunctionPrototype()");
  return nullptr;
}

// Create a new MachineFunctionRaiser object and add it to the list of
// MachineFunction raiser objects of this module.
MachineFunctionRaiser *AMDGPUModuleRaiser::CreateAndAddMachineFunctionRaiser(
    Function *f, const ModuleRaiser *mr, uint64_t start, uint64_t end) {
  MachineFunctionRaiser *mfRaiser = new MachineFunctionRaiser(
      *M, mr->getMachineModuleInfo()->getOrCreateMachineFunction(*f), mr, start,
      end);
  mfRaiser->setMachineInstrRaiser(new AMDGPUMachineInstructionRaiser(
      mfRaiser->getMachineFunction(), mr, mfRaiser->getMCInstRaiser()));
  mfRaiserVector.push_back(mfRaiser);
  return mfRaiser;
}
