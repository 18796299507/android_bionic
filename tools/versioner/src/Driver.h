/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <set>
#include <string>
#include <unordered_map>

#include <llvm/ADT/IntrusiveRefCntPtr.h>

#include "Arch.h"
#include "DeclarationDatabase.h"
#include "VFS.h"

struct CompilationRequirements {
  std::vector<std::string> headers;
  std::vector<std::string> dependencies;
};

void initializeTargetCC1FlagCache(llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> vfs,
                                  const std::set<CompilationType>& types,
                                  const std::unordered_map<Arch, CompilationRequirements>& reqs);

void compileHeader(llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> vfs,
                   HeaderDatabase* header_database, CompilationType type,
                   const std::string& filename);
