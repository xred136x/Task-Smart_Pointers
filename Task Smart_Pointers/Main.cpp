#include<iostream>
#include<memory>

class Parent {
public:
	virtual void Func() {
		std::cout << "ParentFunc\n";
	}
	const std::string getName()const {
		return _name;
	}
	void setName(std::string& name) {
		_name = name;
	}
private:
	std::string _name;
};
class Child : public Parent {
public:
	void Func() override {
		std::cout << "ChildFunc\n";
	}
	const int getAge()const {
		return _age;
	}
	void setAge(int age) {
		_age = age;
	}
private:
	int _age = 0;
};

int main() {

	std::shared_ptr<Parent> pr = std::make_shared<Child>();
	pr->Func();
	std::shared_ptr<Child> pr2 = std::dynamic_pointer_cast<Child>(pr);
	pr2->Func();
	

	return 0;
}