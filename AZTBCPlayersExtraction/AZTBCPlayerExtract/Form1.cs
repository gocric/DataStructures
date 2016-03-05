using OfficeOpenXml;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AZTBCPlayerExtract
{
    public class TeamList
    {
        public string TeamID { get; set; }
        public string TeamName { get; set; }
        public List<string> PlayersList { get; set; }
    }


    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string html = "";
            Dictionary<string, string> teamids = new Dictionary<string, string>();
            List<TeamList> teamlist = new List<TeamList>();

            {
                //Create request for given url
                string url = "http://aztbc.com/web/team";
                HttpWebRequest request = (HttpWebRequest)HttpWebRequest.Create(url);
                request.MaximumAutomaticRedirections = 5000;
                CookieContainer cookie = new CookieContainer();
                request.CookieContainer = cookie;
                request.Method = "GET";
                //Create response-object
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                //Take response stream
                StreamReader sr = new StreamReader(response.GetResponseStream());

                //Read response stream (html code)
                html = sr.ReadToEnd();

                //Close streamreader and response
                sr.Close();
                response.Close();
            }
            {
                string strRegex = @"<a href=" + "\"/web/team/[0-9]{1,4}\">([A-z]|" + @"\s){2,1000}</a>";
                Regex myRegex = new Regex(strRegex, RegexOptions.None);


                foreach (Match myMatch in myRegex.Matches(html))
                {
                    if (myMatch.Success)
                    {
                        // Add your code here
                        var teamname = Regex.Replace(myMatch.Value, @"<a href=" + "\"/web/team/[0-9]{1,4}\">", "").Replace("</a>", "");

                        var teamid = Regex.Match(myMatch.Value, "/web/team/[0-9]{1,4}").Value.Replace("/web/team/", "");

                        teamids.Add(teamid, teamname);
                    }
                }
            }
            foreach (var teamid in teamids)
            {
                TeamList teamlis = new TeamList();

                string url = "http://aztbc.com/web/team/" + teamid.Key;
                HttpWebRequest request = (HttpWebRequest)HttpWebRequest.Create(url);
                request.MaximumAutomaticRedirections = 5000;
                CookieContainer cookie = new CookieContainer();
                request.CookieContainer = cookie;
                request.Method = "GET";
                //Create response-object
                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                //Take response stream
                StreamReader sr = new StreamReader(response.GetResponseStream());

                //Read response stream (html code)
                html = sr.ReadToEnd();

                //Close streamreader and response
                sr.Close();
                response.Close();

                string strRegex = @"<a href=" + "\"/web/player/show/playerid/[0-9]{1,6}\">([A-z]|" + @"\s){2,1000}</a>";
                Regex myRegex = new Regex(strRegex, RegexOptions.None);
                List<string> playerslist = new List<string>();

                foreach (Match myMatch in myRegex.Matches(html))
                {
                    if (myMatch.Success)
                    {
                        var tempstring = Regex.Replace(myMatch.Value, @"<a href=" + "\"/web/player/show/playerid/[0-9]{1,6}" + "\">", "").Replace("</a>", "");
                        if (!playerslist.Contains(tempstring))
                        {
                            playerslist.Add((tempstring));
                        }

                    }
                }

                teamlis.PlayersList = playerslist;
                teamlis.TeamID = teamid.Key;
                teamlis.TeamName = teamid.Value;


                teamlist.Add(teamlis);
            }


            using (var package = new ExcelPackage(new FileInfo("D:/AZTBC.xlsx")))
            {
                // add a new worksheet to the empty workbook
                foreach (var val in teamlist)
                {
                    ExcelWorksheet worksheet = package.Workbook.Worksheets.Add(val.TeamName);
                    for (int i = 1; i <= val.PlayersList.Count; i++)
                    {
                        worksheet.Cells[i, 1].Value = val.PlayersList[i - 1];
                    }

                    
                }
                // --------- Data and styling goes here -------------- //
                package.Save();
            }
        }


    }
}
