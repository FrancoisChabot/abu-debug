// Copyright 2021 Francois Chabot

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ABU_DEBUG_H_INCLUDED
#define ABU_DEBUG_H_INCLUDED

#include <cassert>

namespace abu::dbg {
#if defined(__GNUC__)
[[noreturn]] inline __attribute__((always_inline)) void unreachable() {
  __builtin_unreachable();
}
#elif defined(_MSC_VER)
[[noreturn]] __forceinline void unreachable() {
  __assume(false);
}
#else
inline void unreachable() {}
#endif
}  // namespace abu::dbg

#if defined(NDEBUG)
#if defined(_MSC_VER)
#define abu_assume __assume
#else
#define abu_assume(condition) \
  if (!(condition)) abu::dbg::unreachable()
#endif
#else  // NDEBUG
#define abu_assume(condition) assert(condition)
#endif

#define abu_precondition(condition) abu_assume(condition)
#define abu_postcondition(condition) abu_assume(condition)

#endif