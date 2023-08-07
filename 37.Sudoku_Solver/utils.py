from typing import List, TypeVar, Set

T = TypeVar('T')

def intersection(*args: List[T]) -> List[T]:
    if not args:
        return []
    
    # Convert each list to a set and take the intersection of all sets
    result_set: Set[T] = set(args[0])
    for arg in args[1:]:
        result_set &= set(arg)

    return list(result_set)
