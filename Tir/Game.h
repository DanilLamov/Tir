#ifndef GAME_H
#define GAME_H

class Game {
public:
    //����������� �� ���������
    Game() = delete;
    //�����������
    Game(const unsigned int& windowWidth, const unsigned int& windowHeight);
    //����������
    ~Game() = default;
    //����������� �����������
    Game(const Game&) = delete;
    //����������� �������������
    Game& operator = (const Game&) = delete;
    //����������� �����������
    Game(Game&&) = delete;
    //����������� ������������� ������������
    Game& operator = (Game&&) = delete;

    void init();
    void input(const float& dt);
    void update(const float& dt);
    void render();

    void pressKey(const size_t& key);
    void releaseKey(const size_t& key);

private:
    enum GameState {
        GAME_ACTIVE,
        GAME_MENU,
        GAME_WIN,
        GAME_PAUSE
    };

    GameState gameState;
    unsigned int windowWidth, windowHeight;
    bool keys[1024];

};

#endif