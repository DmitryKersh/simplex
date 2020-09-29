#include "table.h"

int main() {
    /*
    CanonicalTask task = read_task(cin);

    Print(parse_func(task.function));

    for (const string& s : task.conditions) {
        Print(parse_condition(s));
    }
*/
    CanonicalTask task;
    task.var_number = 3;
    task.conditions_number = 3;
    task.conditions = {"4x1 + x2 + x3 <= 5", "x1 + 2x2 <= 3", "x2 + 8x3 <= 16"};
    task.function = "6x1 + 6x2 + 6x3 => max";

    Table table(task);

    cout << "Initial table:" << endl;
    table.print_table(cout);

    try {
        table.solve_simplex();
    }
    catch (std::out_of_range& e) {
        cout << e.what();
    }

    return 0;
}

