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

    // Trying to use a locker
    Locker lock(isolate);

    // Create a stack-allocated handle scope.
    HandleScope handle_scope(isolate);

    // Create a new context.
    Local<Context> context = Context::New(isolate);

    // Enter the context for compiling and running the hello world script.
    Context::Scope context_scope(context);

    // Create a string containing the JavaScript source code.
    Local<String> source = String::NewFromUtf8(isolate, "function foo() { return 3 * 11 }; foo();");

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

  isolate->Dispose();
  V8::Dispose();
  
  // Dispose the isolate and tear down V8.
  return 0;
}
