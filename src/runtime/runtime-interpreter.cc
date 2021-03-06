// Copyright 2015 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/runtime/runtime-utils.h"

#include "src/arguments.h"
#include "src/isolate-inl.h"

namespace v8 {
namespace internal {


RUNTIME_FUNCTION(Runtime_InterpreterEquals) {
  HandleScope scope(isolate);
  DCHECK_EQ(2, args.length());
  CONVERT_ARG_HANDLE_CHECKED(Object, x, 0);
  CONVERT_ARG_HANDLE_CHECKED(Object, y, 1);
  Maybe<bool> result = Object::Equals(x, y);
  if (result.IsJust()) {
    return isolate->heap()->ToBoolean(result.FromJust());
  } else {
    return isolate->heap()->exception();
  }
}


RUNTIME_FUNCTION(Runtime_InterpreterNotEquals) {
  HandleScope scope(isolate);
  DCHECK_EQ(2, args.length());
  CONVERT_ARG_HANDLE_CHECKED(Object, x, 0);
  CONVERT_ARG_HANDLE_CHECKED(Object, y, 1);
  Maybe<bool> result = Object::Equals(x, y);
  if (result.IsJust()) {
    return isolate->heap()->ToBoolean(!result.FromJust());
  } else {
    return isolate->heap()->exception();
  }
}


RUNTIME_FUNCTION(Runtime_InterpreterLessThan) {
  HandleScope scope(isolate);
  DCHECK_EQ(2, args.length());
  CONVERT_ARG_HANDLE_CHECKED(Object, x, 0);
  CONVERT_ARG_HANDLE_CHECKED(Object, y, 1);
  Maybe<bool> result = Object::LessThan(x, y);
  if (result.IsJust()) {
    return isolate->heap()->ToBoolean(result.FromJust());
  } else {
    return isolate->heap()->exception();
  }
}


RUNTIME_FUNCTION(Runtime_InterpreterGreaterThan) {
  HandleScope scope(isolate);
  DCHECK_EQ(2, args.length());
  CONVERT_ARG_HANDLE_CHECKED(Object, x, 0);
  CONVERT_ARG_HANDLE_CHECKED(Object, y, 1);
  Maybe<bool> result = Object::GreaterThan(x, y);
  if (result.IsJust()) {
    return isolate->heap()->ToBoolean(result.FromJust());
  } else {
    return isolate->heap()->exception();
  }
}


RUNTIME_FUNCTION(Runtime_InterpreterLessThanOrEqual) {
  HandleScope scope(isolate);
  DCHECK_EQ(2, args.length());
  CONVERT_ARG_HANDLE_CHECKED(Object, x, 0);
  CONVERT_ARG_HANDLE_CHECKED(Object, y, 1);
  Maybe<bool> result = Object::LessThanOrEqual(x, y);
  if (result.IsJust()) {
    return isolate->heap()->ToBoolean(result.FromJust());
  } else {
    return isolate->heap()->exception();
  }
}


RUNTIME_FUNCTION(Runtime_InterpreterGreaterThanOrEqual) {
  HandleScope scope(isolate);
  DCHECK_EQ(2, args.length());
  CONVERT_ARG_HANDLE_CHECKED(Object, x, 0);
  CONVERT_ARG_HANDLE_CHECKED(Object, y, 1);
  Maybe<bool> result = Object::GreaterThanOrEqual(x, y);
  if (result.IsJust()) {
    return isolate->heap()->ToBoolean(result.FromJust());
  } else {
    return isolate->heap()->exception();
  }
}


RUNTIME_FUNCTION(Runtime_InterpreterStrictEquals) {
  SealHandleScope shs(isolate);
  DCHECK_EQ(2, args.length());
  CONVERT_ARG_CHECKED(Object, x, 0);
  CONVERT_ARG_CHECKED(Object, y, 1);
  return isolate->heap()->ToBoolean(x->StrictEquals(y));
}


RUNTIME_FUNCTION(Runtime_InterpreterStrictNotEquals) {
  SealHandleScope shs(isolate);
  DCHECK_EQ(2, args.length());
  CONVERT_ARG_CHECKED(Object, x, 0);
  CONVERT_ARG_CHECKED(Object, y, 1);
  return isolate->heap()->ToBoolean(!x->StrictEquals(y));
}


RUNTIME_FUNCTION(Runtime_InterpreterToBoolean) {
  SealHandleScope shs(isolate);
  DCHECK_EQ(1, args.length());
  CONVERT_ARG_CHECKED(Object, x, 0);
  return isolate->heap()->ToBoolean(x->BooleanValue());
}


RUNTIME_FUNCTION(Runtime_InterpreterLogicalNot) {
  SealHandleScope shs(isolate);
  DCHECK_EQ(1, args.length());
  CONVERT_ARG_CHECKED(Object, x, 0);
  return isolate->heap()->ToBoolean(!x->BooleanValue());
}


RUNTIME_FUNCTION(Runtime_InterpreterTypeOf) {
  SealHandleScope shs(isolate);
  DCHECK_EQ(1, args.length());
  CONVERT_ARG_HANDLE_CHECKED(Object, x, 0);
  return Object::cast(*Object::TypeOf(isolate, x));
}


RUNTIME_FUNCTION(Runtime_InterpreterNewClosure) {
  HandleScope scope(isolate);
  DCHECK_EQ(2, args.length());
  CONVERT_ARG_HANDLE_CHECKED(SharedFunctionInfo, shared, 0);
  CONVERT_SMI_ARG_CHECKED(pretenured_flag, 1);
  Handle<Context> context(isolate->context(), isolate);
  return *isolate->factory()->NewFunctionFromSharedFunctionInfo(
      shared, context, static_cast<PretenureFlag>(pretenured_flag));
}

}  // namespace internal
}  // namespace v8
