std::vector<int> createVector() {
    std::vector<int> local = {1, 2, 3, 4, 5};
    return std::move(local);  //RVO won't happen
}

int main() {
    std::vector<int> v = createVector();
}