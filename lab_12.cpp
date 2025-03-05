#include <iostream>
#include <string>
using namespace std;
//статические поля и статические методы класса - почитать!
/*static позволяет вызывать методы без создания объекта.
Т.е. нам не выгодно создавать объект класса,
который не имеет своих данных и нужен для обработки данных какго-то другого объекта.
Пример с std :: cout << object. 
Вызов метода происходит через область видимости*/
class Image
{
    private:
    int height;
    int width;
    int size;

    public:
    Image (int _height = 0, int _width = 0, int _size = 0)
    {
        height = _height;
        width = _width;
        size = _size;
    }
    int Get_Height()
    {
        return height;
    }
    int Get_Width()
    {
        return width;
    }
    int Get_Size()
    {
        return size;
    }
};

class Url
{
    private:
    string url;

    public:
    Url (string _url = "")
    {
        url = _url;
    }
    string Get_Url ()
    {
        return url;
    }
};

class Account
{
    private:
    string name;
    int age;

    public:
    Account(string _name = "", int _age = 0)
    {
        name = _name;
        age = _age;
    }
    string Get_Name()
    {
        return name;
    }
    int Get_Age()
    {
        return age;
    }
};

class ImageEditing
{
    public:
    static Image Resize(Image image, int _height, int _width) // изменение размеров изображения
    {
        cout << "You have changed the width and height" << endl;
        return image;
    }

    static Image InvertColors(Image image) // изменить цвета на изображении
    {
        cout << "The colors are inverted" << endl;
        return image;
    }
};

class ImageFileSystem
{
    public:
    static void Save(Image image) // сохранение изображение в файловой системе
    {
        cout << "The image is saved" << endl;
        return;
    }
    
    static int DeleteDuplicates() // удалить из файловой системы все дублирующиеся изображения и вернуть количество удаленных
    {
        int count = 0;
        // идёт подсчёт и удаление
        cout << "Duplicates are deleted" << endl;
        return count;
    }

    //создание дубликата
    //перемещение картинок в файловой системе
    //...
};

class ImageNetwork
{
    public:
    static byte* Download(Url imageUrl) // загрузка битового массива с изображением с помощью HTTP запроса
    {
        byte* image_byte = nullptr;
        cout << "Image downloaded" << endl;
        return image_byte;
    }
};

class ImageAccount
{
    public:
    static Image SetImageAsAccountPicture(Image image, Account account) // запрос к БД для сохранения ссылки на это изображение для пользователя
    {
        cout << "The image is installed in the account profile" << endl;
        return image;
    } 

    // удаление изображения из профиля
    // замена изображения в профиле
};

int main ()
{
    Image image;
    
    //ImageEditing edit;
    //image = edit.InvertColors(image);
    //image = edit.Resize(image, image.Get_Height(), image.Get_Width());
    ImageEditing :: InvertColors(image);
    ImageEditing :: Resize(image, image.Get_Height(), image.Get_Width());
    
    ImageFileSystem :: Save(image);
    int count = ImageFileSystem :: DeleteDuplicates();

    Account User ("Ivan", 25);
    ImageAccount :: SetImageAsAccountPicture(image, User);

    Url link ("https://lms.tsu.ru/pluginfile.php/1/theme_adaptable/logo/1741065024/%D0%BB%D0%BE%D0%B3%D0%BE%20%D1%81%D1%82%D0%B0%D0%BD%D0%B4%D0%B0%D1%80%D1%82%20%D0%B2%D0%B5%D1%80%D1%81%D0%B8%D1%8F%202.png");
    //ссылка на логотип из moodle
    byte* bit_arr;
    bit_arr = ImageNetwork :: Download(link);

    return 0;
}
