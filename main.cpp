#include "table.h"

int main() {
    CanonicalTask task = read_task(cin);

    Print(parse_func(task.function));

    for (const string& s : task.conditions) {
        Print(parse_condition(s));
    }

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
