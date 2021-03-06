/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#pragma once

#include "InternalFunction.h"

namespace JSC {

template<typename ViewClass>
class JSGenericTypedArrayViewConstructor : public InternalFunction {
public:
    typedef InternalFunction Base;

protected:
    JSGenericTypedArrayViewConstructor(VM&, Structure*);
    void finishCreation(VM&, JSGlobalObject*, JSObject* prototype, const String& name, FunctionExecutable* privateAllocator);

public:
    static JSGenericTypedArrayViewConstructor* create(
        VM&, JSGlobalObject*, Structure*, JSObject* prototype, const String& name, FunctionExecutable* privateAllocator);

    // FIXME: We should fix the warnings for extern-template in JSObject template classes: https://bugs.webkit.org/show_bug.cgi?id=161979
#if COMPILER(CLANG)
#if __has_warning("-Wundefined-var-template")
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wundefined-var-template"
#endif
#endif
    DECLARE_INFO;
#if COMPILER(CLANG)
#if __has_warning("-Wundefined-var-template")
#pragma clang diagnostic pop
#endif
#endif
    
    static Structure* createStructure(VM&, JSGlobalObject*, JSValue prototype);

protected:
    static ConstructType getConstructData(JSCell*, ConstructData&);
    static CallType getCallData(JSCell*, CallData&);
};

} // namespace JSC
