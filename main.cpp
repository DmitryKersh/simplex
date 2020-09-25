#include "parsers.h"




int main() {
    CanonicalTask task = read_task(cin);

    Print(parse_func(task.function));

    for (const string& s : task.conditions) {
        Print(parse_condition(s));
    }
    
    return 0;
}
