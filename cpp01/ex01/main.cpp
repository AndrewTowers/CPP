#include "Zombie.hpp"

int main() {
    int N = 5;
    Zombie* heapZombie = zombieHorde(N, "Heap");
    for (int i = 0;i < N;i++) {
        heapZombie[i].announce();
    }
    delete[] heapZombie;

    return 0;
}
