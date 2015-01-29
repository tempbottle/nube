//
// Nube
//
//
// a cloud scripting server based in google v8 and boost libraries.
// nube means cloud in spanish.
//

#include <v8.h>
#include <string>
#include <vector>

using namespace std;
using namespace v8;

// needed macros
// ...

// class definiton
class Nube {

private:
    Isolate* isolate;

    static void Log(const FunctionCallbackInfo<Value> &args);
    static void FetchScript(const string& path);
    const string ExcuteScript(const string& scriptData, const string& scriptName, bool *resultError);
    // vector of classes and functions

public:

    static void Include(const FunctionCallbackInfo<Value>& args);
    static void Version(const FunctionCallbackInfo<Value>& args);

    static void Initialize();
    static void Dispose();
    Nube(void);
   ~Nube(void);

};
