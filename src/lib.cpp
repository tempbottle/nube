//
// Nube
//
//
// a cloud scripting server based in google v8 and boost libraries.
// nube means cloud in spanish.
//

#include <v8.h>

using namespace v8; // but of course
// using namespace internal;


// constructor
Nube::Nube(void) {

    // should isolate be created here
    // exportFunctions = new vector<nube_export_func *>();
}

Nube::~Nube(void) {

}

// log from inside script
void Nube::Log(const FunctionCallbackInfo<Value>& args){
    HandleScope handle_scope(args.GetIsolate());
    String::Utf8Value str(args[0]);

    printf("%s\r\n", js_safe_str(*str));
    args.GetReturnValue().Set(Undefined(args.GetIsolate()));
}

// returns version
Nube::Version(const FunctionCallbackInfo<Value>& args ){

}

// fetch script from database
Nube::FetchScript(const string& path) {
    // path is a /organization/script url

}

// we might need a bytecode cache for compiled scripts
// Nube::ScriptCache() { }

// used with previous method
// Nube::CompileScript (const string& script) { }


// should load includes from export path (or config file)
void Nube::Include(const FunctionCallbackInfo<Value>& args) {

}

// for the time being...
const string Nube::ExcuteScript(const string& scriptData, const string& scriptName, bool *resultError) {

    string res;
    bool isError = false

    {
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

            // for iter to expose libraries

            // context to run
            Local<Context> context = Context::New(isolate, NULL, global);

            if (context.IsEmpty()) {
                return "Failed to create new JS context";
            }

            // make the source
            Handle<String> source = String::NewFromUtf8(isolate, scriptData.c_str());

            // compile the script (should go on separate method);
            Handle<Script> script = Script::Compile(source, Local<Value>::New(isolate, String::NewFromUtf8(isolate, fileName.c_str())));

            // we should check exceptions but first wanna make it run
            Handle<Value> result = script->Run();

            String::Utf8Value ascii(result);
            if (*ascii) {
                res = *ascii;
            }

            // forces gc after execution
            DisposeActiveInstances();
        }

        isolate->SetData(0, NULL);
    }

    return res;
}


// wraps V8::Dispose
void Nube::Initialize() {

    V8::InitializeICU();
    // V8::Initialize();
}

// wraps V8::Dispose
void Nube::Dispose() {

    V8::LowMemoryNotification();
    while (!V8::IdleNotification()) { }

    V8::Dispose();
}
