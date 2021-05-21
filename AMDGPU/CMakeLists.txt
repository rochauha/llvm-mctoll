include_directories(
  ${LLVM_MAIN_SRC_DIR}/lib/Target/AMDGPU
  ${LLVM_BINARY_DIR}/lib/Target/AMDGPU
  ${CMAKE_CURRENT_SOURCE_DIR}/..
)

if(NOT LLVM_MCTOLL_BUILT_STANDALONE)
  set(LLVM_MCTOLL_DEPS intrinsics_gen AMDGPUCommonTableGen)
endif()

add_llvm_library(AMDGPURaiser STATIC
  AMDGPUModuleRaiser.cpp
  AMDGPUMachineInstructionRaiser.cpp

  DEPENDS
  ${LLVM_MCTOLL_DEPS}
)
