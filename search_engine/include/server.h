#pragma once

#include "inverted_index.h"

struct RelativeIndex{
    size_t doc_id;
    float rank;
    bool operator ==(const RelativeIndex& other) const;
};

class SearchServer {
public:
/**
* @param idx � ����������� ������ ��������� ������ �� �����
InvertedIndex,
* ����� SearchServer ��� ������ ������� ���� ����������� �
�������
*/
    SearchServer(InvertedIndex &idx);

/**
* ����� ��������� ��������� ��������
* @param queries_input ��������� ������� ������ �� �����
requests.json
* @return ���������� ��������������� ������ ����������� ������� ���
�������� ��������
*/

    std::vector<std::vector<RelativeIndex>> search(const std::vector<std::string>& queries_input);
private:
    InvertedIndex _index;
};