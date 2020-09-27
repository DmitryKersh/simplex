#include "table.h"

int main() {
    CanonicalTask task = read_task(cin);

    Print(parse_func(task.function));

    for (const string& s : task.conditions) {
        Print(parse_condition(s));
    }

    Table table(task);

    table.solve_simplex();

    return 0;
}
