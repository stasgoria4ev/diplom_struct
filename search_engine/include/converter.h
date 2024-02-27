#pragma once

#include "nlohmann/json.hpp"

class MissingConfigFieldException: public std::exception {
public:
    const char* what() const noexcept override;
};

class NoFileConfigJsonException: public std::exception {
public:
    const char* what() const noexcept override;
};

/**
* Класс для работы с JSON-файлами
*/
class ConverterJSON {

public:
    ConverterJSON();

    nlohmann::json FileDict(std::ifstream& file);

/**
* Метод получения содержимого файлов
* @return Возвращает список с содержимым файлов перечисленных
* в config.json
*/
    std::vector<std::string> GetTextDocuments();
/**
* Метод считывает поле max_responses для определения предельного
* количества ответов на один запрос
* @return
*/
    static int GetResponsesLimit();
/**
* Метод получения запросов из файла requests.json
* @return возвращает список запросов из файла requests.json
*/
    std::vector<std::string> GetRequests();
/**
* Положить в файл answers.json результаты поисковых запросов
*/
    void putAnswers(std::vector<std::vector<std::pair<int, float>>> answers);
};