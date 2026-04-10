from importlib.metadata import version, PackageNotFoundError

try:
    __version__ = version("pycades")
except PackageNotFoundError:
    __version__ = "0.0.0-unknown"

from ._pycades import *
