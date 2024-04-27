#include "Lamps.h"
#include "Set.h"

int main()
{
    setlocale(0, "");
    Set A;
    int answer;
    do
    {
        std::cout << "\n1. ����\n";
        std::cout << "2. �������� ������� � ���������\n";
        std::cout << "3. ����������\n";
        std::cout << "4. �������������� �� Set � Lamps\n";
        std::cout << "5. �������������� �� Lamps � Set\n";
        std::cout << "6. ��������� \n";
        std::cout << "7. ��������� \n";
        std::cout << "8. ~ \n";
        std::cout << "9. ����� \n\n";
        std::cout << "10. ����� \n";

        std::cin >> answer;

        switch (answer)
        {
        case 1:

            A.Input();

            break;

        case 2:
        {
            int x;
            std::cout << "\n������� ����� ����� ������ �������� � ���������: ";
            std::cin >> x;
            A = A + x;
            (A).Show();
            break;
        }



        case 3:
        {
            Set B;
            B.Input();
            A = (A + B);
            (A).Show();
            break;
        }



        case 4:
        {
            Lamps bitField;
            bitField = A;
            bitField.Show();
            break;
        }


        case 5:
        {
            int count;
            std::cout << "\n������� ���������� ���������: ";
            std::cin >> count;
            Lamps bitField(count);
            bitField.Input();
            Set c(bitField);
            c.Show();
            break;
        }



        case 6:
        {
            Set B;
            B.Input();
            A = A * B;
            (A).Show();
            break;

        }


        case 7:
        {
            Set B;
            B.Input();
            std::cout << ((A == B) ? "\nA == B" : "\nA != B");
            break;
        }



        case 8:
        {
            (~A).Show();
            break;
        }

        case 9:
        {
            A.Show();
            break;
        }

        default:

            break;
        }

    } while (answer != 11);

}