//
// Nube
//
//
// a cloud scripting server based in google v8 and boost libraries.
// nube means cloud in spanish.
//

#include <v8.h>
#include <string>
#include <iostream>
#include <vector>
#include "lib.hpp"

using namespace v8;
using namespace std;


// constructor
Nube::Nube(void) {

    // isolate should  be created here

    isolate = Isolate::New();

    // todo keep vector of instances
}

// destructor can be tricky
Nube::~Nube(void) {


    // destroy vector of instances
}

// check init
void Nube::Initialize(void) {

    V8::InitializeICU();
    // V8::Initialize();
}

// wraps V8::Dispose
void Nube::Dispose() {

    // V8::LowMemoryNotification();
    // while (!V8::IdleNotification()) { }

    V8::Dispose();
}

// for the time being...
const string Nube::ExcuteScript(const string& scriptData, const string& scriptName, bool *resultError) {

    string res;
    bool isError = false;

    Locker lock(isolate);
    Isolate::Scope iscope(isolate);
    {
        // create a stack-allocated handle scope.
        HandleScope scope(isolate);

        // review this
        isolate->SetData(0, this);

        // global object
        Handle<ObjectTemplate> global = ObjectTemplate::New();

        global->Set(String::NewFromUtf8(isolate, "require"), FunctionTemplate::New(isolate, Include));
        global->Set(String::NewFromUtf8(isolate, "log"), FunctionTemplate::New(isolate, Log));

        // context to run
        Local<Context> context = Context::New(isolate, NULL, global);

        if (context.IsEmpty()) {
            return "Failed to create new context";
        }

        // source and script name
        Handle<String> source = String::NewFromUtf8(isolate, "3 * 11"); //scriptData.c_str());
        Local<String> scriptName = String::NewFromUtf8(isolate, "fooScript");

        // compile the script (should go on separate method)
        Handle<Script> script = Script::Compile(source, scriptName);

        // we should check exceptions but first wanna make it run
        Handle<Value> result = script->Run();

        String::Utf8Value ascii(result);
        if (*ascii) {
            res = *ascii;
        }

        // forces gc after execution
        // not v8 defined
        // DisposeActiveInstances();
    }

    isolate->SetData(0, NULL);
    // should destroy isolate
    return res;
}

// further functionality

// log from inside script
void Nube::Log(const FunctionCallbackInfo<Value>& args){
    HandleScope handle_scope(args.GetIsolate());
    String::Utf8Value str(args[0]);

    printf("%s\n", *str);
    args.GetReturnValue().Set(Undefined(args.GetIsolate()));
}

// returns version
void Nube::Version(const FunctionCallbackInfo<Value>& args){
}

// fetch script from database
void Nube::FetchScript(const string& path) {
    // path is a /organization/script url
}

// we might need a bytecode cache for compiled scripts
// Nube::ScriptCache() { }

// used with previous method
// Nube::CompileScript (const string& script) { }


// should load includes from export path (or config file)
void Nube::Include(const FunctionCallbackInfo<Value>& args) {

}


