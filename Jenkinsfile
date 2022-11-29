pipeline {
    //runs on agent1
    agent { node { label 'agent1' } }
    stages {
        stage('build') {
            steps {
                sh 'g++ --coverage -g -O0  -fprofile-arcs -ftest-coverage -I/usr/include/gtest -L/usr/lib/x86_64-linux-gnu test_fun.cpp -lgtest -lpthread'
            }
        }
        stage('test') {
            steps {
                sh './a.out --gtest_output="xml:./tests.xml"; gcovr --xml coverage.cobertura.xml'
            }
        }
    }
}
