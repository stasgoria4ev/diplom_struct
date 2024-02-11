#pragma once

struct Entry {
    size_t doc_id, count;
// Данный оператор необходим для проведения тестовых сценариев
    bool operator ==(const Entry& other) const;
};

//std::mutex flow_access;
void Flow(std::vector <std::string> flow, std::map<std::string, std::vector<Entry>> (*freq_dictionary));

class InvertedIndex {
public:
    InvertedIndex();

    /**
     * Данное значение оператора необходимо для проведения тестового сценария,
     * в основной программе значение пробрасывается с main.
     */
    [[maybe_unused]] int max_responses{};

    std::vector<std::string> streams[3];//ко-во ядер/потоков/нитей ПОКА ТОЛЬКО ОДНА ЦИФРА
    int streamsSize{};
    int streamsSizeTemp{};
    /**
    * Обновить или заполнить базу документов, по которой будем совершать
поиск
    * @param texts_input содержимое документов
    */

    void UpdateDocumentBase(std::vector<std::string> input_docs);

    /**
    * Метод определяет количество вхождений слова word в загруженной базе
документов
    * @param word слово, частоту вхождений которого необходимо определить
    * @return возвращает подготовленный список с частотой слов
    */
    std::vector<Entry> GetWordCount(const std::string& word);

private:
    std::vector<std::string> docs;//список содержимого документов или коллекция для хранения текстов
        // документов, ..деляет doc_id дл..
    std::map<std::string, std::vector<Entry>> freq_dictionary;//частотный словарь
};