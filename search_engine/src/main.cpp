#include <iostream>
#include <vector>
#include "converter.h"
#include "inverted_index.h"
#include "server.h"

int main() {
    ConverterJSON converterJSON;
    InvertedIndex invertedIndex;
    try {
        invertedIndex.UpdateDocumentBase(converterJSON.GetTextDocuments());
    }
    catch (const NoFileConfigJsonException& x) {
        std::cerr << "Cought exception: " << x.what() << '\n';
        exit(1);
    }
    catch (const MissingConfigFieldException& x) {
        std::cerr << "Cought exception: " << x.what() << '\n';
        exit(1);
    }
    catch (const nlohmann::json::parse_error& x) {
        std::cerr << "Exception found in config.json: " << x.what() << '\n';
        exit(1);
    }
    catch (const nlohmann::json::type_error& y) {
        std::cerr << "Exception found in config.json: " << y.what() << '\n';
        exit(1);
    }
    catch (...) {
        std::cerr << "Some exception occurred in config.json...\n";
        exit(1);
    }

    invertedIndex.max_responses = ConverterJSON::GetResponsesLimit();//проброс max_responses в SearchServer через _index(idx)

    SearchServer searchServer(invertedIndex);

    try {
        std::vector<std::vector<RelativeIndex>> searchServerSearch = searchServer.search(converterJSON.GetRequests());
        std::vector<std::vector<std::pair<int, float>>> answersTemp;
        for (auto &i: searchServerSearch) {
            std::vector<std::pair<int, float>> answersTempJ;
            for (auto &j: i) {
                answersTempJ.emplace_back(std::pair(j.doc_id, j.rank));
            }
            answersTemp.push_back(answersTempJ);
        }
        converterJSON.putAnswers(answersTemp);
    }
    catch (const nlohmann::json::parse_error& x) {
        std::cerr << "Exception found in requests.json: " << x.what() << '\n';
        exit(1);
    }
    catch (const nlohmann::json::type_error& y) {
        std::cerr << "Exception found in requests.json: " << y.what() << '\n';
        exit(1);
    }
    catch (...) {
        std::cerr << "Some exception occurred in requests.json...\n";
        exit(1);
    }
    std::cout << "SUCCESS. Ending \"SkillboxSearchEngine\".\n";
}