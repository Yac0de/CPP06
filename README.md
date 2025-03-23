# CPP Module 06 – Type Casting, Serialization & Runtime Type Identification

## Table of Contents

1. [Project Overview](#project-overview)
2. [Key Concepts Introduced](#key-concepts-introduced)
   - [C++ Cast Operators](#c-cast-operators)
   - [Serialization & Deserialization](#serialization--deserialization)
   - [Runtime Type Identification](#runtime-type-identification)
3. [Exercise Breakdown](#exercise-breakdown)
   - [Ex00: Casting Around](#ex00-casting-around)
   - [Ex01: Pointers and Serialization](#ex01-pointers-and-serialization)
   - [Ex02: Type Discovery](#ex02-type-discovery)
4. [Compiling and Running](#compiling-and-running)
5. [Conclusion & What’s Next](#conclusion--whats-next)

---

## Project Overview

This module takes a step closer to the low-level mechanics of C++. It introduces four key areas:

- **Static and dynamic type casting**
- **Manual serialization**
- **Reinterpretation of memory**
- **Runtime type discovery** without relying on standard RTTI tools

It offers essential tools to understand how C++ handles memory, object identity, and polymorphism.

---

## Key Concepts Introduced

### C++ Cast Operators

C++ provides four casting operators that are more type-safe than C-style casts:

- `static_cast<T>(value)` – used for well-defined, compile-time conversions.
  **Example:**
  ```cpp
  float f = static_cast<float>(42); // int to float
  Base* b = static_cast<Base*>(derivedPtr); // Derived* to Base*
  ```

- `dynamic_cast<T>(ptr)` – used with polymorphic base classes to safely cast at runtime.
  **Example:**
  ```cpp
  Base* base = new Derived();
  Derived* derived = dynamic_cast<Derived*>(base);
  if (derived) derived->doSomething();
  ```

- `reinterpret_cast<T>(ptr)` – reinterprets bits of one type as another (low-level, risky).
  **Example:**
  ```cpp
  int* iptr = new int(42);
  char* cptr = reinterpret_cast<char*>(iptr); // treat int memory as bytes
  ```

- `const_cast<T>(ptr)` – adds or removes `const` qualifier.
  **Example:**
  ```cpp
  const int* c = new int(5);
  int* modifiable = const_cast<int*>(c); // now writable (be careful!)
  ```

### Serialization & Deserialization

We simulate serialization by converting a pointer to an integer (`uintptr_t`) and back. This allows passing raw memory safely between layers.

```cpp
uintptr_t raw = serialize(ptr);
Data* recovered = deserialize(raw);
```

This is essential in systems like networking, file I/O, or interprocess communication.

### Runtime Type Identification

In Ex02, we generate random objects from a base class pointer and must identify their true type without using `typeid` or RTTI.

We achieve this using `dynamic_cast`:

```cpp
Base* base = generate();
if (dynamic_cast<A*>(base)) { std::cout << "It's A!"; }
```

This is a core use case of polymorphism in real-world code (e.g., dynamic plugin loaders).

---

## Exercise Breakdown

### Ex00: Casting Around

**Goal:** Practice with `static_cast`, `reinterpret_cast`, and `const_cast`.

We learn:

- Basic syntax and purpose of each C++ cast
- Avoiding undefined behavior when casting between unrelated types

This forms the foundation of safe, intentional type conversion.

### Ex01: Pointers and Serialization

**Goal:** Serialize a pointer to an integer and restore it.

We learn:

- What serialization really means: transforming a structure into a transferable form
- The role of `reinterpret_cast` and `uintptr_t` for raw memory conversion

This simulates low-level serialization and deserialization logic.

### Ex02: Type Discovery

**Goal:** Create a base class and derive three subclasses (`A`, `B`, `C`), then randomly generate one and identify its type using `dynamic_cast`.

We learn:

- How to detect object type through a base pointer
- When `dynamic_cast` fails (returns null or throws exception for references)
- Practical use of RTTI in a clean, idiomatic C++ way

---

## Compiling and Running

1. Go to an exercise directory:

```sh
cd ex02
```

2. Build:

```sh
make
```

3. Run:

```sh
./identifier
```

4. Clean:

```sh
make clean
make fclean
make re
```

---

## Conclusion & What’s Next

CPP06 reveals some of the internal mechanics of how C++ handles object identity, pointer reinterpretation, and runtime behavior:

- Understand **cast safety** and why C++ introduced stricter casting rules
- Learn **serialization basics** by simulating pointer storage
- Use **`dynamic_cast`** to safely downcast in polymorphic hierarchies

In **CPP07**, we will dive into **templates**, enabling us to write type-independent code with maximum reusability and efficiency.

