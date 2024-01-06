#include <SFML/Graphics.hpp>
#include "src/Loops/mainLoopClass.h"
#include "src/Window/windowClass.h"

int main(){
    window w(1);
    mainLoop ml(1);

    ml.gameLoop(w.gameWindow);
}
