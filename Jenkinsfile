pipeline {
    agent any
    stages {
        stage('build') {
            steps {
                bash 'g++ --coverage -g -O0  -fprofile-arcs -ftest-coverage -I/usr/include/gtest -L/usr/lib/x86_64-linux-gnu test_fun.cpp -lgtest -lpthread'
            }
        }
        stage('test') {
            steps {
                bash './a.out --gtest_output="xml:./tests.xml"; gcovr --xml coverage.cobertura.xml'
            }
        }
    }
}
