//My Approach : 
  /*
  Here, I will use its first row and first column as an indicator of whether to make this entire row or column zero or not. 

Suppose I found that Matrix[4][5]=0, then I will make Matrix[0][5] and Matrix[4][0] as 0 to indicate that entire row 4 and column 5 have to be zero.

One problem that will arise here is that the first row or column itself contains zero elements. For this, I will use three variables that will indicate whether the first row, first column, or first element is zero or not.

Now, first, I will check for the first element, the first row, and the first column and mark these three variables corresponding to the result.

After that, I will traverse through the entire matrix, and, as I said earlier, I will use the first row and column for indicators.

Now, after marking the first row and the first column by traversing the entire matrix, I will mark rows and columns as zero according to the first row and the first column.

Then we will check for those three variables that we defined earlier, and according to that, we will mark the first row and first column as zero or not.

  */


class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) 
    {
        bool firstRow=false,firstCol=false,firstElement=false;    
        if(mat[0][0]==0)
            firstElement=true;
        for(int j=1;j<mat[0].size();j++)
            if(mat[0][j]==0)
                firstRow=true;
        for(int i=1;i<mat.size();i++)
            if(mat[i][0]==0)
                firstCol=true;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    mat[0][j]=0;
                    mat[i][0]=0;
                }
            }
        }

        for(int j=1;j<mat[0].size();j++)
        {
            if(mat[0][j]==0)
            {
                for(int i=0;i<mat.size();i++)
                {
                    mat[i][j]=0;
                }
            }
        }
        for(int i=1;i<mat.size();i++)
        {
            if(mat[i][0]==0)
            {
                for(int j=0;j<mat[0].size();j++)
                {
                    mat[i][j]=0;
                }
            }
        }

        if(firstElement)
        {
            for(int j=0;j<mat[0].size();j++)
                mat[0][j]=0;
            for(int i=0;i<mat.size();i++)
                mat[i][0]=0;
        }
        if(firstCol)
        {
            for(int i=0;i<mat.size();i++)
                mat[i][0]=0;
        }
        if(firstRow){
            for(int j=0;j<mat[0].size();j++)
                mat[0][j]=0;
        }

    }
};
