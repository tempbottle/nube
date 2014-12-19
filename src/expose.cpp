    /*

    */

#include <iostream>
#include <v8.h>
// #include "../common/common.h"
    
using namespace v8;

        /* a simple print function, for printing information to stdout */
    Handle<Value> printMessage(const Arguments& args) 
    {
        Locker locker;
        HandleScope scope;

            //The arguments that are handed in have some valuable information
            //tucked away inside it. Such as the function or object that it was
            //called from (in this case, global) and also can be a variable length.
            //Most times, you can access the arguments directly as args[ index ].
            //Also note how you can use To(Type)->(Type)Value() to get the value.
            //For example, args[1]->ToBoolean()->BooleanValue();

        if( args.Length() ) 
        {
            String::Utf8Value message( args[0]->ToString() );
            if( message.length() ) 
            {
                //Print the message to stdout
                printf( "%s", *message );

                    //Here we assume newline, and then if the second parameter
                    //is supplied to the function, use that instead.
                bool newline = true;
                if(args.Length() == 2) 
                {
                    newline = args[1]->ToBoolean()->BooleanValue();
                }

                if(newline) printf("\n");

                return scope.Close( Boolean::New( true ) );
            }
        } 

            //In js, functions that do not return a value by default return undefined.
            //We will follow suite, instead of returning a value we return no values, the return
            //value in script will be undefined. 
                //var x = print('no return value');
                //print(x);  //spits out 'undefined'.

        return Undefined();
    }

    int main(int argc, char **argv) 
    {

        Locker locker;
        HandleScope handle_scope;

        Handle<ObjectTemplate> globalTemplate = ObjectTemplate::New();

            //Here, we can now expose the printMessage function. Note that it is
            //done before the context is created (obviously, for it to exist in that context).

                //This creates a new global function object called print();
            globalTemplate->Set( String::New("print"), FunctionTemplate::New( printMessage ));

            //Create our main context
        Handle<Context> context = Context::New( NULL, globalTemplate );

        if(argc > 1) {

            eScriptExecResult r = executeScript( std::string( argv[1] ) , context );

        } else {

            printf("Usage: <scriptname.js> \n Execute the javascript file.");

        }

        return 0;
    }



