import os
import subprocess
from pathlib import Path

import nox

nox.options.reuse_existing_virtualenvs = True
nox.options.default_venv_backend = "uv|virtualenv"


def add_uv_to_environ() -> None:
    """Add UV Python directories to PATH environment variable."""
    path_to_uv_pythons = subprocess.run(
        ["uv", "python", "dir"],
        env={"NO_COLOR": "1", **os.environ},
        check=True,
        capture_output=True,
        text=True,
    ).stdout.strip()

    bin_paths = [str(p) for p in Path(path_to_uv_pythons).glob("*/bin")]
    os.environ["PATH"] = ":".join(bin_paths + [os.environ["PATH"]])


add_uv_to_environ()


@nox.session(python=["3.9", "3.10", "3.11", "3.12", "3.13"])  # type: ignore
def tests(session: nox.Session) -> None:
    """Run pytest with coverage on the source code."""
    session.install("-r", "tests/requirements.txt", ".")
    session.run(
        "pytest",
        "--cov=src",
        *session.posargs,
    )
