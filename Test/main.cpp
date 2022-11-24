#include <QCoreApplication>

#include <listnode.h>
#include <listrand.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto path = "C:/Users/WerKEK/Documents/Test/test.txt";
    ListRand inputList, outputList;
    FILE *file;

    fopen_s(&file, path, "wb");

    inputList.AddElement("qwe");
    inputList.AddElement("qwer");
    inputList.AddElement("qwert");
    inputList.AddElement("qwerty");
    inputList.AddElement("qwertyu");
    inputList.AddElement("qwertyui");
    std::cout << "InputList" << std::endl;
    inputList.GetRand();
    inputList.Serialize(file);
    fclose(file);

    fopen_s(&file, path, "rb");
    outputList.Deserialize(file);
    std::cout << std::endl << "OutputList " << std::endl;
    outputList.GetRand();

    system("pause");
    return a.exec();
}
