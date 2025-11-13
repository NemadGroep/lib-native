"""lib-native: Native C++ extensions for ORDRSP processing."""

from __future__ import annotations

# Import the C++ extension module
try:
    from ._core import add
except ImportError as e:
    import warnings
    warnings.warn(f"Failed to import C++ extension module: {e}")
    # Fallback pure Python implementation
    def add(i: int, j: int) -> int:
        """Fallback Python implementation of add."""
        return i + j

def hello() -> str:
    """Simple hello function."""
    return "Hello from lib-native!"

__all__ = ["add", "hello"]

