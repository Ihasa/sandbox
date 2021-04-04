using System;
using System.IO;
using NPOI.SS.UserModel;
using NPOI.HSSF.UserModel;
using NPOI.XSSF.UserModel;
// .NET FrameworkのコンパイラならC:/Windows/Microsoft.NET/Framework64/[バージョン]/にパスを通すだけ
// .NET Core使うなら→https://docs.microsoft.com/ja-jp/dotnet/core/get-started
//  dotnet new --output プロジェクト名
//  dotnet run --project プロジェクト名
//  NPOI使って空xlsx作るexample→ https://qiita.com/hukatama024e/items/37427f2578a8987645dd

namespace hoge
{
    public class Hello
    {
        static void Main()
        {
            try {
                string filePath = "sample.xlsx";

                //ブック作成
                var book = CreateNewBook( filePath );

                //シート無しのexcelファイルは保存は出来るが、開くとエラーが発生する
                book.CreateSheet( "newSheet" );

                //ブックを保存
                using( var fs = new FileStream( filePath, FileMode.Create ) ) {
                    book.Write( fs );
                }
            }
            catch( Exception ex ) {
                Console.WriteLine( ex );
            }
        }

                //ブック作成
        static IWorkbook CreateNewBook( string filePath )
        {
            IWorkbook book;
            var extension = Path.GetExtension( filePath );

            // HSSF => Microsoft Excel(xls形式)(excel 97-2003)
            // XSSF => Office Open XML Workbook形式(xlsx形式)(excel 2007以降)
            if( extension == ".xls" ) {
                book = new HSSFWorkbook();
            }
            else if( extension == ".xlsx" ) {
                book = new XSSFWorkbook();
            }
            else {
                throw new ApplicationException( "CreateNewBook: invalid extension" );
            }

            return book;
        }
    }
}
