/*
Question :
Create ExcelSheet that has following three operations :
1) SetIntValue
2) SetFormula
3) Evaluate

sheet.SetIntValue("CELL1", 1); //Sets value 1 to cell1
sheet.SetFormula("CELL3", “CELL1", "CELL2"); // cell3 <- cell1+cell2
r = sheet.Evaluate(“CELL2”); //returns result object
assert(r.value == 0);
assert(r.error == “not set”);
*/



#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const string NOT_SET = "not set";
const string CYCLE_DETECTED = "cycle detected";
const string NO_ERROR = "";

struct CellVal{
    int val;
    pair<string,string> formula;
    bool isFormulaSet;

    CellVal(){}
    CellVal(int v, pair<string,string> f, bool i) : val(v), formula(f), isFormulaSet(i) {}
};

struct Result{
    int value;
    string error;

    Result() {}
    Result(int v,string e) : value(v), error(e) {}
};

class Sheet{
private:
    unordered_map<string,CellVal> keyMap;

    Result evaluateRec(string key, unordered_set<string>& cycleSet){

        if(cycleSet.find(key) != cycleSet.end()){
            return Result(0, CYCLE_DETECTED);
        }
        cycleSet.insert(key);

        Result res;
        if(keyMap.find(key) == keyMap.end()){
            res = Result(0, NOT_SET);
        }
        else if(keyMap[key].isFormulaSet == false){
            res = Result(keyMap[key].val, NO_ERROR);
        }
        else {
            Result res1 = evaluateRec(keyMap[key].formula.first, cycleSet);
            Result res2 = evaluateRec(keyMap[key].formula.second, cycleSet);
        
            if(res1.error != NO_ERROR || res2.error != NO_ERROR){
                res = Result(0, (res1.error.empty() ? res2.error : res1.error));
            }
            else{
                res = Result(res1.value + res2.value, NO_ERROR);
            }
        }
        cycleSet.erase(key);
        
        return res;
    }

public:
    Sheet(){
        keyMap = unordered_map<string,CellVal>();
    }

    void setIntValue(string key, int val){
        keyMap[key] = CellVal(val, make_pair("",""), false);
    }

    void setFormula(string resKey, string inputKey1, string inputKey2){
        keyMap[resKey] = CellVal(0, make_pair(inputKey1,inputKey2), true);
    }

    Result evaluate(string key){
        unordered_set<string> cycleSet;
        return evaluateRec(key, cycleSet);
    }
};

int main(){
    Sheet sheet;
    
    // Test 1
    sheet.setIntValue("CELL1", 1);
    Result r = sheet.evaluate("CELL1");
    assert(r.value == 1);
    assert(r.error == NO_ERROR);

    // Test 2
    r = sheet.evaluate("CELL2");
    assert(r.value == 0);
    assert(r.error == NOT_SET);

    // Test 3
    sheet.setFormula("CELL3", "CELL1", "CELL2"); // cell3 <- cell1+cell2
    r = sheet.evaluate("CELL3");
    assert(r.value == 0);
    assert(r.error == NOT_SET);

    // Test 4
    sheet.setIntValue("CELL2", 2);
    r = sheet.evaluate("CELL3");
    assert(r.value == 3);
    assert(r.error == NO_ERROR);

    // Test 5
    sheet.setIntValue("CELL1", 3);
    r = sheet.evaluate("CELL3");
    assert(r.value == 5);
    assert(r.error == NO_ERROR);

    // Test 6
    sheet.setFormula("CELL4", "CELL1", "CELL3"); // cell4 <- cell1+cell3
    r = sheet.evaluate("CELL4");
    assert(r.value == 8);
    assert(r.error == NO_ERROR);

    // Test 7
    sheet.setFormula("CELL6", "CELL5", "CELL3"); // cell5 <- cell5+cell3
    sheet.setFormula("CELL5", "CELL6", "CELL1"); // cell5 <- cell6+cell1
    r = sheet.evaluate("CELL6");
    assert(r.value == 0);
    assert(r.error == CYCLE_DETECTED);

    // Test 8
    sheet.setIntValue("CELL6", 10);
    r = sheet.evaluate("CELL6");
    assert(r.value == 10);
    assert(r.error == NO_ERROR);

    // Test 9
    r = sheet.evaluate("CELL5");
    assert(r.value == 13);
    assert(r.error == NO_ERROR);

    return 0;
}