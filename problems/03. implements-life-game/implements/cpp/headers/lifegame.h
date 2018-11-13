#include "map.h"

namespace loadcomplete {
    template <const int HEIGHT, const int WIDTH>
    class LifeGame {
     public:
        void StartGame();

     private:
        void InitializeMapByInput();
        void ProcessLifeOfUnits();
        
        Map<HEIGHT, WIDTH> map;
    };

    template <const int HEIGHT, const int WIDTH>
    void LifeGame<HEIGHT, WIDTH>::InitializeMapByInput() {
        int age;

        for (int i{0}; i < HEIGHT; ++i) {
            for (int j{0}; j < WIDTH; ++j) {
                std::cin >> age;
                map.GetUnitsFromNow()[i][j].SetAge(age);
            }
        }
    }


    template <const int HEIGHT, const int WIDTH>
    void LifeGame<HEIGHT, WIDTH>::ProcessLifeOfUnits() {
        map.MoveToNextGeneration();
        map.ChangeGeneration();
        map.GrowAllUnits();
        map.CheckAllUnits();
    }

    template <const int HEIGHT, const int WIDTH>
    void LifeGame<HEIGHT, WIDTH>::StartGame() {
        InitializeMapByInput();
        while (map.HasLivingUnit()) {
            ProcessLifeOfUnits();
        }
    }
}