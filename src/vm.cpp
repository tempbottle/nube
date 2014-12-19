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

// we need a handle to return from script
typedef v8::internal::Arguments Arguments;

Handle<Value> send_response(const Arguments &args);

Handle<Value> send_response(const Arguments &args) {

    if (args.Empty()) {
        std::cout << "args is empty" << std::endl;
    }

    /*

    HandleScope scope;
    v8::String::AsciiValue username(args[0]);
    wc::TUserInfo ui = {0};

    // return v8::Undefined();

    v8::Handle<v8::Object> result = v8::Object::New();
    result->Set(v8_str("Id"),    v8_num(ui.Id));
    result->Set(v8_str("Name"),  v8_str(ui.Name));
    result->Set(v8_str("Title"), v8_str(ui.Title));

    scope.Close(result);
    */
}


// work on this http://stackoverflow.com/questions/8992087/using-stringify-from-the-v8-shell
/*
Handle<Value> parseJson(Handle<Value> jsonString) {
    HandleScope scope;

    Handle<Context> context = Context::GetCurrent();
    Handle<Object> global = context->Global();

    Handle<Object> JSON = global->Get(String::New("JSON"))->ToObject();
    Handle<Function> JSON_parse = Handle<Function>::Cast(JSON->Get(String::New("parse")));

    // return JSON.parse.apply(JSON, jsonString);
    return scope.Close(JSON_parse->Call(JSON, 1, &jsonString));
}
*/


// main function
int main(int argc, char* argv[]) {

  // Initialize V8.
  V8::InitializeICU();
  V8::Initialize();

  // V8::SetCaptureStackTraceForUncaughtExceptions(true, 10, StackTrace::kDetailed);

  // Create a new Isolate and make it the current one.
  Isolate* isolate = Isolate::New();
  {
    Isolate::Scope isolate_scope(isolate);



    // Create a stack-allocated handle scope.
    HandleScope handle_scope(isolate);

    // Create a new context.
    Local<Context> context = Context::New(isolate);

    // Enter the context for compiling and running the hello world script.
    Context::Scope context_scope(context);

    // Create a string containing the JavaScript source code.
    Local<String> source = String::NewFromUtf8(isolate, "3 * 11");

    // Name the script
    Local<String> name = String::NewFromUtf8(isolate, "fooScript");

    // Compile the source code.
    Local<Script> script = Script::Compile(source, name);

    // Run the script to get the result.
    Local<Value> result = script->Run();

    // Convert the result to an UTF8 string and print it.
    String::Utf8Value utf8(result);
    printf("%s\n", *utf8);
  }
  
  // Dispose the isolate and tear down V8.
  isolate->Dispose();
  V8::Dispose();
  return 0;
}
