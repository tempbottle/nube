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

using namespace v8;

// needed macros
// ...


// definitions
#define js_safe_str(s) (s ? s : "")


// stuff borrowed from fs mod_v8

/* js constructor callback definition */
typedef void * void_pointer_t;
typedef void_pointer_t (*ConstructorCallback)(const FunctionCallbackInfo<Value>& info);

/* js constructor callback definition */
typedef void * void_pointer_t;
typedef void_pointer_t (*ConstructorCallback)(const v8::FunctionCallbackInfo<v8::Value>& info);

/* js function definition */
typedef struct {
    const char *name;           /* Name of the function */
    v8::FunctionCallback func;        /* Function callback */
} js_function_t;

/* js property definition */
typedef struct {
    const char *name;           /* Name of the property */
    v8::AccessorGetterCallback get;     /* The property getter */
    v8::AccessorSetterCallback set;     /* The property setter */
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
vector

    // vector of classes and functions

public:
    Nube(void); // constructor
   ~Nube(void); // desctructor
    


}
