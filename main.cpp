#include <iostream>
static int count;
int showMenu()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {

        std::cout<<std::endl;
        std::cout << "____________________МЕНЮ____________________" << std::endl;
        std::cout << " 1.      Показать всё" << std::endl;
        std::cout << " 2.      Добавить новую информацию" << std::endl;
        std::cout << " 3.      STOP" << std::endl;
        std::cout<<std::endl;
        std::cout << "Введите число [1 , 3]" << std::endl;
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a <= 0) or (a>5)) // если предыдущее извлечение оказалось неудачным
        {
            std::cout<<"НЕПРАВИЛЬНЫЙ ВВОД В МЕНЮ"<<std::endl;
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a

            return a;
    }
}


class A;
class B;
class Box;

class Common{
friend class Box;
public:

    int qwerty;

    Common()
    {
        qwerty=12345;
    }

    virtual void print_all();
};

void Common::print_all()
{
    std::cout<<"Common))"<<std::endl;
}


class For_A{
public:
    int aA;
    For_A(){
        aA=98;
    }

    void show();
};
void For_A::show() {
    std::cout<<"show A: "<<aA<<std::endl;
}

class A: public Common{
    friend class Box;
private:
    int private_a_A;
    void private_print_a() const
    {
        std::cout<<"this is a_A "<<private_a_A<<std::endl;
    }
protected:
    int protected_b_A;
    void protected_print_b() const
    {
        std::cout<<"this is b_A "<<protected_b_A<<std::endl;
    }
public:
    For_A for_A;
    int public_c_A;
    void public_print_c() const {
        std::cout<<"this is c_A "<<public_c_A<<std::endl;
    }

    int public_get_a() const {
        return private_a_A;
    }


    A(){
        private_a_A=10;
        protected_b_A=20;
        public_c_A=30;
    }
    ~A(){
        std::cout<<"destructor A"<<std::endl;
    }
    void print_all() override;



};

void A::print_all() {
    A *Obj = this;
    for (int i=0; i<count; i++)
    {
        std::cout<<"A: "<<Obj[i].private_a_A<<" "<<Obj[i].protected_b_A<<" "<<Obj[i].public_c_A<<" "<<Obj[i].qwerty<<std::endl;
    }
}

class B: public Common {
    friend class Box; //надо!
private:
    int private_a_B;
    void private_print_a_B() const
    {
        std::cout<<"this is a_B "<<private_a_B<<std::endl;
    }
protected:
    int protected_b_B;
    void protected_print_b_B() const
    {
        std::cout<<"this is b_B "<<protected_b_B<<std::endl;
    }
public:
    int public_c_B;
    void public_print_c_B() const {
        std::cout<<"this is c_B "<<public_c_B<<std::endl;
    }
    int public_get_a_B() const {
        return private_a_B;
    }

    B(){
        private_a_B=100;
        protected_b_B=200;
        public_c_B=300;
    }
    ~B(){
        std::cout<<"destructor B"<<std::endl;
    };
    void print_all() override;


};

void B::print_all() {
    B *Obj = this;
    for (int i=0; i<count; i++)
    {
        std::cout<<"B: "<<Obj[i].private_a_B<<" "<<Obj[i].protected_b_B<<" "<<Obj[i].public_c_B<<" "<<Obj[i].qwerty<<std::endl;
    }
}




class Box: public A, public B {

public:

//    friend class A;
//    friend class B;

    A* class_A_array;
    B* class_B_array;

    Box()
    {
        class_A_array = new A[0];
        class_B_array = new B[0];
    }

    void addElement()
    {
        A* tmpA;
        B* tmpB;
        std::cout<<sizeof(A)<<std::endl;
        tmpA = (A*)std::realloc(class_A_array, (count + 1) * sizeof(A));
        tmpB = (B*)std::realloc(class_B_array, (count + 1) * sizeof(B));

        if ((tmpA != nullptr) && (tmpB != nullptr))
        {
            class_A_array = tmpA;
            class_B_array = tmpB;


            std::cout<<"let's add some new things!!!!!!!!!"<<std::endl;
            int new_public_a, new_public_b;
            int new_protected_a, new_protected_b;
            int new_private_a, new_private_b;
            int new_qwerty_a, new_qwerty_b;

            std::cout<<"for public A goes: ";
            std::cin>>new_public_a;
            class_A_array[count].public_c_A = new_public_a;
            std::cout<<"for protected A goes: ";
            std::cin>>new_protected_a;
            class_A_array[count].protected_b_A = new_protected_a;
            std::cout<<"for private A goes: ";
            std::cin>>new_private_a;
            class_A_array[count].private_a_A = new_private_a;
            std::cout<<" "<<std::endl;
            std::cout<<"for qwerty A goes: ";
            std::cin>>new_qwerty_a;
            class_A_array[count].qwerty = new_qwerty_a;
            std::cout<<" "<<std::endl;



            std::cout<<"for public B goes: ";
            std::cin>>new_public_b;
            class_B_array[count].public_c_B = new_public_b;
            std::cout<<"for protected B goes: ";
            std::cin>>new_protected_b;
            class_B_array[count].protected_b_B = new_protected_b;
            std::cout<<"for private B goes: ";
            std::cin>>new_private_b;
            class_B_array[count].private_a_B = new_private_b;
            std::cout<<" "<<std::endl;
            std::cout<<"for qwerty B goes: ";
            std::cin>>new_qwerty_b;
            class_B_array[count].qwerty = new_qwerty_b;
            std::cout<<" "<<std::endl;

            count++;

            std::cout<<"we have: "<<std::endl;
            for (int i = 0; i<count; i++)
            {
                std::cout<<"Public "<<class_A_array[i].public_c_A<<" in A and "<<class_A_array[i].qwerty<<" also "<<class_B_array[i].public_c_B<< " in B"<<" and "<<class_B_array[i].qwerty<<std::endl;
                std::cout<<"Protected "<<class_A_array[i].protected_b_A<<" in A and "<<class_B_array[i].protected_b_B<< " in B"<<std::endl; //можем достать протектед
                std::cout<<"Private "<<class_A_array[i].private_a_A<<" in A and "<<class_B_array[i].private_a_B<< " in B"<<std::endl; //можем достать прайват
            }

        }
        else
        {
            std::cout<<"Бывают в жизни взлёты и падения, но в основном падения\n";
        }
    }

    //void print_all_shit() ;
    void print_all() override;


};

//void Box::print_all_shit(){
//    for (int i=0; i< count; i++)
//    {
//        std::cout<<"A: "<<class_A_array[i].private_a_A<<" "<<class_A_array[i].protected_b_A<<" "<<class_A_array[i].public_c_A<<std::endl;
//        std::cout<<"B: "<<class_B_array[i].private_a_B<<" "<<class_B_array[i].protected_b_B<<" "<<class_B_array[i].public_c_B<<std::endl;
//    }
//
//
//}

void Box::print_all() {
    for (int i=0; i< count; i++)
    {
        std::cout<<"A override: "<<class_A_array[i].private_a_A<<" "<<class_A_array[i].protected_b_A<<" "<<class_A_array[i].public_c_A<<" "<<class_A_array[i].qwerty<<std::endl;
        std::cout<<"B override: "<<class_B_array[i].private_a_B<<" "<<class_B_array[i].protected_b_B<<" "<<class_B_array[i].public_c_B<<" "<<class_B_array[i].qwerty<<std::endl;
    }

}


int main() {

//
    B elementB;
    A elementA;
    count=0;


//
//    Common common;
//    std::cout<< "1) " ;
//    common.print_all_B_A(); //это ничего не выведет потому что это виртуальная функция и в данной записи не понятно что конкретно нам надо ведь у Common эта функция никак не реализована
//    std::cout<<"\n";

    //////так нельзя//////
//    std::cout<< "2) " ;
//    common.class_A->print_all_B_A();
//    std::cout<<"\n";

//    std::cout<< "3) " ;
//    common.class_B->print_all_B_A();
//    std::cout<<"\n";
    //////хз почему//////

    Box element_box;

//    std::cout<<"\n";
//    std::cout<< "4) " ;
//    elementA.print_all_B_A();
//    std::cout<<"\n";
//
//    std::cout<< "5) " ;
//    elementB.print_all_B_A();
//    std::cout<<"\n";
//
//    std::cout<< "6) " ;
//    std::cout<<elementB.qwerty; //к qwerty можно обращаться из В
//    std::cout<<"\n";
//
//    std::cout<< "7) " ;
//    std::cout<<elementA.qwerty; //к qwerty можно обращаться из А
//    std::cout<<"\n";
//
//    std::cout<< "8) " ;
//    std::cout<<common.qwerty; //к qwerty можно обращаться из Common
//    std::cout<<"\n";
//
//    std::cout<< "9) " ;
//    elementA.for_A.show(); //к qwerty можно обращаться из Common
//    std::cout<<"\n";
//
//    std::cout<< "10) " ;
//    element_box.A::print_all_B_A(); //через класс бокс можно теперь достать переменные и методы класса А и В
//    element_box.B::print_all_B_A(); //через класс бокс можно теперь достать переменные и методы класса А и В
//    std::cout<<"\n";


    int a;
    do {

        a = showMenu();

        switch (a)
        {
            case 1: //вывести то что написали щас
//                elementA.print_all(); //выводит конструктор А так как мы не обращаемся к выделенной памяти
//                std::cout<<"------"<<std::endl;
//                elementB.print_all(); //выводит конструктор В так как мы не обращаемся к выделенной памяти
//                std::cout<<"------"<<std::endl;
                //std::cout<<"---1---"<<std::endl;
                //element_box.print_all_shit(); //выводит как надо потому что тут обращаемся к массивам с выделенной памятью
                std::cout<<"---2---"<<std::endl;
                element_box.print_all();
                break;

            case 2: //вывести то что написали щас
                element_box.addElement();
                break;

            default:
                std::cout<<"Неверно введен номер действия"<<std::endl;
                break;

        }

    } while (a != 3);


}
