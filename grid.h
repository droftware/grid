#ifndef grid_h
#define grid_h

#include <vector>
#include <algorithm>

template<typename T>
class grid
{
public:
    grid();
    grid(size_t rows, size_t cols);

    void clear();
    void resize(size_t rows,size_t cols);

    size_t numRows() const;
    size_t numCols() const;
    bool empty() const;
    size_t size() const;

    T& getAt(size_t row,size_t col);
    const T& getAt(size_t row,size_t cols) const;

    typedef typename std::vector<T>::iterator iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    iterator row_begin(size_t row);
    const_iterator row_begin(size_t row) const;
    iterator row_end(size_t row);
    const_iterator row_end(size_t row) const;

    class MutableReference
    {
    public:
        friend class grid;
        T& operator[] (size_t col);

    private:
        MutableReference(grid* owner,size_t row);
        grid* const owner;
        const size_t row;
    };
    MutableReference operator[](size_t row);

    class ImmutableReference
    {
    public:
        friend class grid;
        const T& operator[](size_t col) const;

    private:
        ImmutableReference(const grid* owner,size_t row);
        const grid* const owner;
        const size_t row;
    };
    ImmutableReference operator[](size_t row) const;

    bool operator < (const grid& other) const;
    bool operator > (const grid& other) const;
    bool operator == (const grid& other) const;
    bool operator != (const grid& other) const;
    bool operator <= (const grid& other) const;
    bool operator >= (const grid& other) const;

private:
    std::vector<T> elems;
    size_t rows;
    size_t cols;
};

template<typename T> grid<T>::grid():rows(0),cols(0){
}

template<typename T> grid<T>::grid(size_t rows,size_t cols)
    :elems(rows * cols),rows(rows),cols(cols){
}

template<typename T> void grid<T>::clear(){
    resize(0,0);
}

template<typename T> void grid<T>::resize(size_t rows,size_t cols){
    //elems.assign(rows * cols,ElemType());
    this->rows = rows;
    this->cols = cols;
}

template<typename T> size_t grid<T>::numRows() const{
    return rows;
}

template<typename T> size_t grid<T>::numCols() const{
    return cols;
}

template<typename T> bool grid<T>::empty() const{
    return size() == 0;
}

template<typename T> size_t grid<T>::size() const{
    return rows * cols;
}

template<typename T> T& grid<T>::getAt(size_t row,size_t col){
    return elems[col + cols * row];
}

template<typename T> const T& grid<T>::getAt(size_t row,size_t col) const{
    return elems[col + cols * row];
}

template<typename T> typename grid<T>::iterator grid<T>::begin(){
    return elems.begin();
}

template<typename T> typename grid<T>::const_iterator grid<T>::begin() const{
    return elems.begin();
}

template<typename T> typename grid<T>::iterator grid<T>::end(){
    return elems.end();
}

template<typename T> typename grid<T>::const_iterator grid<T>::end() const{
    return elems.end();
}

template<typename T> typename grid<T>::iterator grid<T>::row_begin(size_t row){
    return begin() + row * numCols();
}

template<typename T> typename grid<T>::const_iterator grid<T>::row_begin(size_t row) const{
    return begin() + row * numCols();
}

template<typename T> typename grid<T>::iterator grid<T>::row_end(size_t row){
    return row_begin(row) + numCols();
}

template<typename T> typename grid<T>::const_iterator grid<T>::row_end(size_t row) const{
    return row_begin(row) + numCols();
}
/*--------------*/

template<typename T> grid<T>::MutableReference::MutableReference(grid* owner,size_t row)
    :owner(owner),row(row){
}

template<typename T> T& grid<T>::MutableReference::operator[](size_t col){
    return owner->getAt(row,col);
}

template<typename T> typename grid<T>::MutableReference grid<T>::operator[](size_t row){
    return MutableReference(this,row);
}
/*--------------*/

template<typename T> grid<T>::ImmutableReference::ImmutableReference(const grid* owner,size_t row)
    :owner(owner),row(row){
}

template<typename T> const T& grid<T>::ImmutableReference::operator[](size_t col) const{
    return owner -> getAt(row,col);
}

template<typename T> typename grid<T>::ImmutableReference grid<T>::operator[](size_t row) const{
    return ImmutableReference(this,row);
}

template<typename T> bool grid<T>::operator < (const grid& other) const{
    if(numRows() != other.numRows())
        return numRows() < other.numRows();

    if(numCols() != other.numCols())
        return numCols() < other.numCols();

    return lexicographical_compare(begin(),end(),other.begin(),other.end());
}

template<typename T> bool grid<T>::operator >= (const grid& other) const{
    return !(*this < other);
}

template<typename T> bool grid<T>::operator > (const grid& other) const{
    return other < *this;
}

template<typename T> bool grid<T>::operator <= (const grid& other) const{
    return !(*this > other);
}

template<typename T> bool grid<T>::operator == (const grid& other) const{
    return (!(*this < other) && !(other < *this));
}

template<typename T> bool grid<T>::operator != (const grid& other) const{
    return (*this < other) || (other < *this);
}

#endif
