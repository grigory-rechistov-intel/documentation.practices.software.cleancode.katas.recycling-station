# Recycling Station

A Kata designed for application of [Command Pattern](https://en.wikipedia.org/wiki/Command_pattern).

## Premise

We operate a recycling station that takes multiple types of garbage and
processes them.
Currently the station supports two kinds of garbage: `ScrapMetal` and `Glass`.
Different garbage pieces need to come to different processing stations for
proper handling. Class `Crusher` works with glass and `Smelter` is for metal.
Processing sequence is different for each station.

Function `recycle()` takes a collection of garbage pieces and it needs to
redirect those pieces to correct stations.

## Incoming change request

We need to add new type of garbage: `OrganicWaste`.
It is to be processed on a new station, `Composter`, by its method `compost()`.

The way it is written now, `recycle()` has to know about what all stations take
and what steps are involved for each garbage piece.

Look at its signature : `recycle(list[Garbage],  smelter, crusher)`
Also, look at its body, it is full of type checks, meaning that needs to know
about all concrete classes of garbage.

We cannot add new type of waste without changing both the signature and
the body of `recycle()`!

## Separating decision from application using Command

Create a function `better_recycle()` that know about neither processing
stations nor processing steps: `better_recycle(list[RecycleCommand])`.

What it should operate on is a *list of command*s, each of which incapsulates
details about the garbage (its type, kind, volume, etc.), which station it
should be passed to, and steps to take to process it.

## Instructions

- Define a Command interface as base for all processing commands.
- Turn existing logic for processing `Glass` and `ScrapMetal` into commands.
  Make it so that all the required knowledge for carrying out a command is saved
  within its object and is available when it is executed.
- Write function `better_recycle()` that takes a list of commands.
- Prepare unit tests as you go, when you feel need for them.
- Do not change existing files that are marked as "third-party".
  Smelter, crusher and garbage are third-party code and cannot be changed.
- Add new garbage type: `OrganicWaste`, a new station `Composter` with method
  `compost()`
- Check that adding the new garbage type does not affect `better_recycle()`.

## Building the code and running the test

1. Recursively clone the repository.
2. For Python: `cd python; ./test_recyclingstation.py`
3. For C++:
   ```
   cd cpp
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ctest
   ```

The existing tests do not test anything beyond the basic ability to invoke
function `recycle()`. Make sure to extend them before you touch any piece of
existing code! For new code, feel free to write new test cases to ensure it
works.