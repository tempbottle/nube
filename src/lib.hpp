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

// lots of stuff borrowed from fs mod_v8

// definitions
#define js_safe_str(s) (s ? s : "")


/* js constructor callback definition */
typedef void * void_pointer_t;
typedef void_pointer_t (*ConstructorCallback)(const FunctionCallbackInfo<Value>& info);

/* js constructor callback definition */
typedef void * void_pointer_t;
typedef void_pointer_t (*ConstructorCallback)(const FunctionCallbackInfo<Value>& info);

/* js function definition */
typedef struct {
    const char *name;           /* Name of the function */
    FunctionCallback func;        /* Function callback */
} js_function_t;

/* js property definition */
typedef struct {
    const char *name;           /* Name of the property */
    AccessorGetterCallback get;     /* The property getter */
    AccessorSetterCallback set;     /* The property setter */
} js_property_t;

/* js class definition */
typedef struct {
    const char *name;           /* The name of the class */
    ConstructorCallback constructor;    /* The constructor definition */
    const js_function_t *functions;     /* An array of function definitions */
    const js_property_t *properties;    /* An array of property definitions */
} js_class_definition_t;


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

    Nube(void); // constructor
   ~Nube(void); // desctructor

};
