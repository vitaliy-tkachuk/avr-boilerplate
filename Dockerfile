# Use an official Ubuntu as a base image
FROM ubuntu:latest

# Install necessary packages
RUN apt-get update && apt-get install -y \
    gcc-avr \
    avr-libc \
    cmake \
    make \
    avrdude

# Create a working directory inside the container
WORKDIR /usr/src/app

# Copy the current directory contents into the container at /usr/src/app
COPY . /usr/src/app

# Command to run CMake and make
CMD ["cmake", ".", "&&", "make"]
