# Get the current working directory; this is the exercise's source folder.
$sourceDir = (Get-Location).Path
# Make the path to the Build folder inside the current working directory.
$buildDir = Join-Path $sourceDir 'Build'

# Create Build if it does not exist; keep any existing files in it.
New-Item -ItemType Directory -Path $buildDir -Force | Out-Null

# Point to the .exercism folder in the source directory.
$sourceExercism = Join-Path $sourceDir '.exercism'

# Point to the copy expected inside Build.
$buildExercism = Join-Path $buildDir '.exercism'

# Copy .exercism only when it is not already present in Build.
if (-not (Test-Path -LiteralPath $buildExercism)) {
    # Copy the whole .exercism folder, including its contents.
    Copy-Item -LiteralPath $sourceExercism -Destination $buildDir -Recurse -Force
}

# Configure CMake using the current directory as source and Build as output.
& cmake -S $sourceDir -B $buildDir -G 'MinGW Makefiles'

# Stop the script with an error if CMake configuration failed.
if ($LASTEXITCODE -ne 0) {
    # Show the native CMake process's exit code in the error message.
    throw "CMake configuration failed with exit code $LASTEXITCODE."
}
