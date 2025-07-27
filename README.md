---

# 🔄 C++ Module 06 – Type Conversions & Casting

This module focuses on **C++ type casting**, **serialization**, and **runtime type identification**.

You’ll implement **scalar conversions**, a **simple serializer**, and **type identification** for polymorphic classes—perfect to deepen your understanding of **static\_cast, reinterpret\_cast, dynamic\_cast, and const\_cast** in **C++17**.

---

## 📌 Table of Contents

* [Overview](#overview)
* [Project Structure](#project-structure)
* [Exercises](#exercises)

  * [ex00 – Scalar Conversion](#ex00--scalar-conversion)
  * [ex01 – Serialization](#ex01--serialization)
  * [ex02 – Identify Real Type](#ex02--identify-real-type)
* [Build & Run](#build--run)
* [Example Usage](#example-usage)
* [Key Concepts Learned](#key-concepts-learned)

---

## ✅ Overview

* **Language:** C++17
* **Key topics covered:**

  * Different types of **C++ casts** (`static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`)
  * Converting between different scalar types
  * Serializing pointers to integer values and back
  * Identifying real runtime types in polymorphic hierarchies

We’ll **modernize the original C++98 tasks** using C++17, improving readability and safety (e.g., using `nullptr`, `<random>` utilities, and structured bindings where useful).

---

## 📂 Project Structure

```
📦 cpp_module_06/
 ├── ex00/
 │   ├── ScalarConverter.hpp / ScalarConverter.cpp
 │   ├── main.cpp
 │   └── Makefile
 ├── ex01/
 │   ├── Serializer.hpp / Serializer.cpp
 │   ├── Data.hpp (custom struct)
 │   ├── main.cpp
 │   └── Makefile
 ├── ex02/
 │   ├── Base.hpp / Base.cpp
 │   ├── A.hpp / B.hpp / C.hpp (derived classes)
 │   ├── identify.cpp
 │   ├── main.cpp
 │   └── Makefile
 └── README.md
```

---

## 📝 Exercises

### **ex00 – Scalar Conversion**

* Implement a **ScalarConverter** class with a single static method:

  ```cpp
  class ScalarConverter {
  public:
      static void convert(const std::string& literal);
  };
  ```

* Takes a string literal and prints it as:

  * **char**
  * **int**
  * **float**
  * **double**

* Must handle:

  * Normal literals → `'c'`, `42`, `4.2f`, `-42.0`
  * Pseudo-literals → `nan`, `+inf`, `-inf`, `nanf`

Example:

```bash
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

---

### **ex01 – Serialization**

* Implement a **Serializer** class that cannot be instantiated and has two static methods:

  ```cpp
  struct Data {
      int value;
      std::string name;
  };

  class Serializer {
  public:
      static uintptr_t serialize(Data* ptr);
      static Data* deserialize(uintptr_t raw);
  };
  ```
* Converts a pointer → integer → pointer.
* Verify that the original pointer and the deserialized pointer refer to the same object.

---

### **ex02 – Identify Real Type**

* Implement:

  ```cpp
  class Base { public: virtual ~Base() = default; };
  class A : public Base {};
  class B : public Base {};
  class C : public Base {};
  ```

* Write:

  * `Base* generate()` → randomly creates `A`, `B`, or `C`.
  * `void identify(Base* p)` → prints actual type (`A`, `B`, `C`).
  * `void identify(Base& p)` → same but using a reference.

* Must **NOT** use `<typeinfo>` (`typeid` or `dynamic_cast` is allowed).

Example:

```cpp
Base* obj = generate();
identify(obj);
identify(*obj);
```

Output example:

```
Generated: B
identify(ptr): B
identify(ref): B
```

---

## 🛠 Build & Run

### Build

Inside any exercise folder:

```bash
make
```

### Run

```bash
./convert 42.0f
./serializer
./identify
```

Since we’re using **C++17**, your Makefile should include:

```make
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
```

---

## ▶ Example Usage

**Serialization example:**

```cpp
int main() {
    Data original{42, "Hello"};
    uintptr_t raw = Serializer::serialize(&original);
    Data* copy = Serializer::deserialize(raw);

    std::cout << "Original: " << original.value << " - " << original.name << "\n";
    std::cout << "Copy: " << copy->value << " - " << copy->name << "\n";
}
```

---

## 🌟 Key Concepts Learned

* ✅ **C++ casting hierarchy** and when to use which cast
* ✅ Handling **special floating-point values** (`nan`, `inf`)
* ✅ Understanding **pointer serialization** with `uintptr_t`
* ✅ Runtime type identification via `dynamic_cast`
* ✅ Safe type conversions and error handling

---
