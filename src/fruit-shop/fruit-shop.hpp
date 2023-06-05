#include <string>

enum class FruitShopState
{
    Welcome,
    MainMenu,
    FruitMenu,
    Exit
};


class FruitShop
{
private:
    FruitShopState state;

    void Welcome();
    void MainMenu();
    void FruitMenu();
    void Exit();

public:
    FruitShop(std::string link = "");
    ~FruitShop();

    void Run();

    void ParseLink(std::string link);
};