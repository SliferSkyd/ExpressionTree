#include <bits/stdc++.h>
#include "parse.h"

std::ifstream inp("test.txt");
std::ofstream out("result.dot");

std::string trace(Tree u) {
    std::string cur = u.node;
    for (auto v: u.children) {
        cur += trace(v);
        out << '\t' << u.id << " -> " << v.id << "\n";
    }
    out << '\t' << u.id << ' ' << "[label=" << "\"" << cur << "\"" << " shape=circle]\n";
    return cur;
}

int main() {
    Parse p(inp);
    Tree result = p.parse();
    out << "digraph \"result\" {\n";
    trace(result);
    out << "}\n";
    std::system("dot -Tpng -o result.png result.dot");
    return 0;
}
