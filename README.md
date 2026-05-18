# Advanced C++ Object-Oriented Architecture & Polymorphism Studio

This repository serves as an engineering gallery focusing on advanced Object-Oriented Programming (OOP) paradigms, robust memory patterns, and deterministic state systems implemented in modern C++. 

The studio demonstrates practical implementations of enterprise-level software design patterns, polymorphic run-time dispatching, resource management, and strict mathematical constraints.

---

## 📐 Architectural Paradigms Showcased

### 1. Run-Time Polymorphism & VTable Dispatching (Factory Payroll Engine)
* **Design Pattern:** Abstract Base Classes (ABC) utilizing pure virtual methods (`virtual double earnings() const = 0;`).
* **Implementation:** Models a structured workplace environment where concrete types (`SalariedEmployee`, `PieceWorker`, `HourlyWorker`) override base interfaces to compute distinct logic dynamically. Demonstrates efficient decoupled processing inside standard polymorphic collections (`std::vector<Employee*>`).
* **Directory:** `/02_Polymorphism_And_Inheritance/Abstract_Base_Classes`

### 2. Object Relationships: Composition vs. Aggregation (The Musician & Library Ecosystems)
* **Composition:** Explores strict lifecycles where child components cannot exist outside their parent container (e.g., a `Student` owning its `Grade` matrix, or a `Mailbox` encapsulating custom tracking objects).
* **Aggregation:** Implements loose lifecycles utilizing weak references or constant pointer tracking (`std::vector<const Instrument*>`), allowing elements to reside independently in global scopes without risking dangling pointer vulnerabilities during teardown loops.
* **Directory:** `/01_Object_Relationships`

### 3. Defensive Programming & Custom Exception Sanitation
* **Core Principle:** Eliminating runtime undefined behavior through compile-time validation rules and standard library error specialization.
* **Coverage:**
  * `std::invalid_argument` checking to catch out-of-boundary simulation factors.
  * `std::overflow_error` monitoring to trap critical divisions by zero within mathematical calculations.
  * `std::out_of_range` indexing guardrails placed inside standard vector processing logic.
* **Directory:** `/04_Robust_Software_Design/exception_sanitation.cpp`

### 4. Deterministic Simulation Systems (Resonant Circuits & Physics Engines)
* **Applications:** Real-world physical simulations matching structural engineering workflows.
  * **Voltage Divider:** Combines component grouping with continuous randomized factor offset simulation to model tolerance fluctuations.
  * **Resonant Circuit:** Employs virtual inheritance structures to translate base circuit configurations into concrete mathematical series or parallel impedance engines.
* **Directory:** `/03_System_Simulations_And_Math`

---

## 🏁 Quality Checklist & Troubleshooting Index

Included at the root level is a comprehensive **C++ Compilation Errors & Solutions Ledger**, capturing solutions to classic object-oriented compilation edge cases discovered during runtime stress-testing:
* Resolving circular include dependencies using modern class forward-declarations.
* Preventing slicing anomalies by validating pointer/object usage.
* Memory health guarantees: Tracking proper array deallocations (`delete[]`) within class destructors to ensure zero memory leaks.
