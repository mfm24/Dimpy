string s="Result";
number n = CountScriptFunctions(s);
result("'"+s+"' has "+n+" functions\n")
//string s2="void Result(long)"
//string s2="void AddScriptFileToMenu( char *fileName, char *commandName, char *menuName, char *optionalSubMenuName, bool isLibrary )"
//string s2="void Result(char *)"
//string s2="void ApplyDataBar( ImageDisplay imgDisp )"
string s2="bool TagGroupGetTagAsString( TagGroup tagGroup, char *tagPath, char **str )"

n=FunctionCountParameters(FindFunctionBySignature(s2))
result("'"+s2+"' has "+n+" parameters\n")

String stub=FunctionGenerateStub(FindFunctionBySignature(s2), 1, 1)
result(stub)


//FunctionCountParameters()
//FunctionGenerateStub